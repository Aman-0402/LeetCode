# Update Rules

Use these rules whenever the instruction says "update".

## What to do on update
1. Read the whole repository root and inspect every top-level problem directory that matches the LeetCode pattern, such as `0001-two-sum`.
2. Detect new problem folders that are not already listed in [Roadmap.md](Roadmap.md) or summarized in [Stats.md](Stats.md).
3. For each new folder, inspect the available solution files to determine the supported languages:
   - `.cpp` → C++
   - `.java` → Java
   - `.py` → Python3
4. Determine solve order for new folders via `git log --diff-filter=A --follow --format=%aI -- <folder>` (earliest commit date), and append them after all existing rows in that chronological order. Do not reorder or renumber existing rows.
5. Determine each new problem's Category from its LeetCode topic tags (e.g. Hash Table, Two Pointers, Sliding Window, Array, Prefix Sum, Math, Simulation, Matrix, Counting, Counting Sort, Greedy).
6. Add new rows to [Roadmap.md](Roadmap.md) as an HTML `<table>` (not a Markdown pipe table), one `<tr>` per language per problem, using `rowspan` to merge the shared columns across a problem's language rows. Columns, in order:
   - S.No
   - Problem No.
   - Problem Name
   - Category
   - Interview Importance (/10)
   - Language (one value per row: C++, Java, or Python3)
   - File Name (a link to that language's solution file, e.g. `<a href="./0001-two-sum/0001-two-sum.cpp">0001-two-sum.cpp</a>`)
7. Keep existing rows intact and append only new problems. Do not remove or overwrite old entries unless the project is explicitly reset.
8. Update [Stats.md](Stats.md) so the category totals and the total-solved count reflect the current repository inventory after additions.
9. If the repository already contains the problem, do not duplicate it in the roadmap.
10. If a problem folder has only a subset of the supported languages, reflect that accurately (fewer rowspan rows, fewer language rows) instead of inventing missing ones.
11. **Never modify [README.md](README.md) as part of an update.** It is maintained separately (auto-generated topic index) and is out of scope.

## Expected behavior
- The update should be based on the actual contents of the workspace, not on memory.
- The table must be built from the current folders in the repository.
- New problems should be added as rows in the roadmap table, in solve order.
- Summary statistics should be updated to match the current number of solved problems.
- README.md is never touched by an update.

## Output format
- Keep the roadmap as an HTML table (rowspan-merged, one row per language) inside [Roadmap.md](Roadmap.md).
- Keep the summary statistics as a Markdown table inside [Stats.md](Stats.md).
- Prefer relative links to the individual solution files (not just the folder) so the roadmap remains portable.
