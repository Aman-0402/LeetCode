# Update Rules

Use these rules whenever the instruction says "update".

## What to do on update
1. Read the whole repository root and inspect every top-level problem directory that matches the LeetCode pattern, such as `0001-two-sum`.
2. Detect new problem folders that are not already listed in [Roadmap.sh](Roadmap.sh) or summarized in [Stats.md](Stats.md).
3. For each new folder, inspect the available solution files to determine the supported languages:
   - `.cpp` → C++
   - `.java` → Java
   - `.py` → Python3
4. Add new rows to the roadmap table in a consistent order, using these columns:
   - S.No
   - Problem No.
   - Problem Name
   - Interview Importance (/10)
   - Language (C++ / Java / Python3)
   - Link
5. Keep existing rows intact and append only new problems. Do not remove or overwrite old entries unless the project is explicitly reset.
6. Update [Stats.md](Stats.md) so the totals reflect the current repository inventory after additions.
7. If the repository already contains the problem, do not duplicate it in the roadmap.
8. If a problem folder has only a subset of the supported languages, reflect that accurately instead of inventing missing ones.

## Expected behavior
- The update should be based on the actual contents of the workspace, not on memory.
- The table must be built from the current folders in the repository.
- New problems should be added as rows in the roadmap table.
- Summary statistics should be updated to match the current number of solved problems.

## Output format
- Keep the roadmap as a Markdown table inside [Roadmap.sh](Roadmap.sh).
- Keep the summary statistics as a Markdown table inside [Stats.md](Stats.md).
- Prefer relative links to the problem folders so the roadmap remains portable.
