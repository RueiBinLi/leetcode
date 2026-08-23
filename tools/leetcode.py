#!/usr/bin/env python3
"""Scaffold, index, and validate this LeetCode solution repository."""

from __future__ import annotations

import argparse
import json
import re
import sys
from datetime import date
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
PROBLEMS = ROOT / "problems"
README = ROOT / "README.md"
START_MARKER = "<!-- PROBLEM_INDEX_START -->"
END_MARKER = "<!-- PROBLEM_INDEX_END -->"
PROBLEM_RE = re.compile(r"^(\d{4,})_(.+)$")
BUCKET_RE = re.compile(r"^(\d{4,})-(\d{4,})$")
STATUSES = {"solved", "review", "mastered"}
DIFFICULTIES = {"easy", "medium", "hard"}


def bucket_name(problem_id: int) -> str:
    start = ((problem_id - 1) // 1000) * 1000 + 1
    return f"{start:04d}-{start + 999:04d}"


def directory_title(title: str) -> str:
    normalized = re.sub(r"[^A-Za-z0-9]+", "_", title).strip("_")
    if not normalized:
        raise ValueError("title must contain a letter or number")
    return normalized


def slug(title: str) -> str:
    return re.sub(r"[^a-z0-9]+", "-", title.lower()).strip("-")


def problem_directories() -> list[Path]:
    return sorted(path for path in PROBLEMS.glob("*/*") if path.is_dir())


def metadata_path(problem_dir: Path) -> Path:
    return problem_dir / "meta.json"


def source_languages(problem_dir: Path) -> list[str]:
    languages: list[str] = []
    if any(problem_dir.rglob("*.cpp")):
        languages.append("cpp")
    if any(problem_dir.rglob("*.py")):
        languages.append("python")
    return languages


def write_json(path: Path, value: dict[str, object]) -> None:
    path.write_text(json.dumps(value, indent=2, ensure_ascii=False) + "\n")


def load_all() -> list[tuple[Path, dict[str, object]]]:
    records: list[tuple[Path, dict[str, object]]] = []
    for problem_dir in problem_directories():
        path = metadata_path(problem_dir)
        if not path.exists():
            raise ValueError(f"missing metadata: {path.relative_to(ROOT)}")
        try:
            metadata = json.loads(path.read_text())
        except (json.JSONDecodeError, OSError) as error:
            raise ValueError(f"cannot read {path.relative_to(ROOT)}: {error}") from error
        records.append((problem_dir, metadata))
    return sorted(records, key=lambda item: int(item[1].get("id", 0)))


def display(value: object) -> str:
    if value is None or value == [] or value == "":
        return "—"
    if isinstance(value, list):
        return ", ".join(str(item) for item in value)
    return str(value)


def generated_index(records: list[tuple[Path, dict[str, object]]]) -> str:
    counts = {status: 0 for status in STATUSES}
    for _, metadata in records:
        status = str(metadata.get("status", ""))
        if status in counts:
            counts[status] += 1

    lines = [
        START_MARKER,
        f"**Total: {len(records)}** · Solved: {counts['solved']} · Review: {counts['review']} · Mastered: {counts['mastered']}",
        "",
        "| ID | Problem | Difficulty | Topics | Language | Status | Solved |",
        "| ---: | --- | --- | --- | --- | --- | --- |",
    ]
    for problem_dir, metadata in records:
        relative = problem_dir.relative_to(ROOT).as_posix()
        problem_id = int(metadata["id"])
        title = str(metadata["title"]).replace("|", "\\|")
        url = metadata.get("url")
        if url:
            problem_link = f"[{title}]({url}) ([code]({relative}))"
        else:
            problem_link = f"[{title}]({relative})"
        lines.append(
            "| {id:04d} | {problem} | {difficulty} | {topics} | {languages} | {status} | {solved} |".format(
                id=problem_id,
                problem=problem_link,
                difficulty=display(metadata.get("difficulty")),
                topics=display(metadata.get("topics")),
                languages=display(metadata.get("languages")),
                status=display(metadata.get("status")),
                solved=display(metadata.get("solved_at")),
            )
        )
    lines.append(END_MARKER)
    return "\n".join(lines)


def indexed_readme(records: list[tuple[Path, dict[str, object]]]) -> str:
    text = README.read_text()
    if START_MARKER not in text or END_MARKER not in text:
        raise ValueError("README is missing problem-index markers")
    before, remainder = text.split(START_MARKER, 1)
    _, after = remainder.split(END_MARKER, 1)
    return before + generated_index(records) + after


def command_index(_: argparse.Namespace) -> int:
    records = load_all()
    README.write_text(indexed_readme(records))
    print(f"Indexed {len(records)} problems in README.md")
    return 0


def solution_template(language: str) -> str:
    if language == "python":
        return "class Solution:\n    pass\n"
    return "#include <iostream>\n\nclass Solution {\npublic:\n  // Implement the solution.\n};\n\nint main() {\n  return 0;\n}\n"


def command_new(args: argparse.Namespace) -> int:
    if args.id < 1:
        raise ValueError("problem ID must be positive")
    dirname = f"{args.id:04d}_{directory_title(args.title)}"
    problem_dir = PROBLEMS / bucket_name(args.id) / dirname
    if problem_dir.exists():
        raise ValueError(f"problem already exists: {problem_dir.relative_to(ROOT)}")

    problem_dir.mkdir(parents=True)
    extension = "py" if args.language == "python" else "cpp"
    (problem_dir / f"main.{extension}").write_text(solution_template(args.language))
    topics = [topic.strip() for topic in args.topics.split(",") if topic.strip()]
    metadata = {
        "id": args.id,
        "title": args.title,
        "url": args.url or f"https://leetcode.com/problems/{slug(args.title)}/",
        "difficulty": args.difficulty,
        "topics": topics,
        "languages": [args.language],
        "status": args.status,
        "solved_at": date.today().isoformat(),
    }
    write_json(problem_dir / "meta.json", metadata)
    (problem_dir / "notes.md").write_text(
        "# Notes\n\n## Approach\n\n## Complexity\n\n- Time: \n- Space: \n\n## Pitfall\n\n## Takeaway\n"
    )
    print(problem_dir.relative_to(ROOT))
    return 0


def validate(records: list[tuple[Path, dict[str, object]]]) -> list[str]:
    errors: list[str] = []
    seen: set[int] = set()
    required = {"id", "title", "url", "difficulty", "topics", "languages", "status", "solved_at"}

    for problem_dir, metadata in records:
        label = problem_dir.relative_to(ROOT)
        missing = required - metadata.keys()
        if missing:
            errors.append(f"{label}: missing fields {', '.join(sorted(missing))}")
            continue
        problem_id = metadata["id"]
        if not isinstance(problem_id, int) or problem_id < 1:
            errors.append(f"{label}: id must be a positive integer")
            continue
        if problem_id in seen:
            errors.append(f"{label}: duplicate problem ID {problem_id}")
        seen.add(problem_id)
        match = PROBLEM_RE.fullmatch(problem_dir.name)
        if not match or int(match.group(1)) != problem_id:
            errors.append(f"{label}: directory ID does not match metadata")
        if problem_dir.parent.name != bucket_name(problem_id):
            errors.append(f"{label}: expected bucket {bucket_name(problem_id)}")
        bucket_match = BUCKET_RE.fullmatch(problem_dir.parent.name)
        if not bucket_match:
            errors.append(f"{label}: invalid bucket name")
        if metadata["difficulty"] not in DIFFICULTIES | {None}:
            errors.append(f"{label}: difficulty must be easy, medium, hard, or null")
        if metadata["status"] not in STATUSES:
            errors.append(f"{label}: invalid status {metadata['status']!r}")
        if not isinstance(metadata["topics"], list) or not isinstance(metadata["languages"], list):
            errors.append(f"{label}: topics and languages must be arrays")
        if not (problem_dir / "main.cpp").exists() and not (problem_dir / "main.py").exists():
            errors.append(f"{label}: missing main.cpp or main.py")
        actual_languages = source_languages(problem_dir)
        if sorted(metadata["languages"]) != sorted(actual_languages):
            errors.append(f"{label}: languages do not match source files ({actual_languages})")
        solved_at = metadata["solved_at"]
        if solved_at is not None:
            try:
                date.fromisoformat(str(solved_at))
            except ValueError:
                errors.append(f"{label}: solved_at must be an ISO date or null")

    for path in PROBLEMS.rglob("*"):
        if path.is_file() and path.suffix == "" and path.name == "main":
            errors.append(f"{path.relative_to(ROOT)}: compiled binary is stored with source")

    expected = indexed_readme(records)
    if README.read_text() != expected:
        errors.append("README problem index is stale; run: python3 tools/leetcode.py index")
    return errors


def command_check(_: argparse.Namespace) -> int:
    records = load_all()
    errors = validate(records)
    if errors:
        for error in errors:
            print(f"error: {error}", file=sys.stderr)
        return 1
    print(f"Validated {len(records)} problems")
    return 0


def parser() -> argparse.ArgumentParser:
    result = argparse.ArgumentParser(description=__doc__)
    commands = result.add_subparsers(dest="command", required=True)

    new = commands.add_parser("new", help="scaffold a new problem")
    new.add_argument("id", type=int)
    new.add_argument("title")
    new.add_argument("--difficulty", choices=sorted(DIFFICULTIES), default=None)
    new.add_argument("--topics", default="", help="comma-separated topics")
    new.add_argument("--language", choices=("cpp", "python"), default="cpp")
    new.add_argument("--status", choices=sorted(STATUSES), default="solved")
    new.add_argument("--url")
    new.set_defaults(handler=command_new)

    index = commands.add_parser("index", help="regenerate the README problem index")
    index.set_defaults(handler=command_index)

    check = commands.add_parser("check", help="validate repository organization")
    check.set_defaults(handler=command_check)

    return result


def main() -> int:
    try:
        args = parser().parse_args()
        return args.handler(args)
    except ValueError as error:
        print(f"error: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
