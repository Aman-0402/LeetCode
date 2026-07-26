from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:

        freq = [0] * 26

        for task in tasks:
            freq[ord(task) - ord('A')] += 1

        freq.sort()

        maxFreq = freq[-1]
        idleSlots = (maxFreq - 1) * n

        for i in range(24, -1, -1):
            if idleSlots <= 0:
                break
            idleSlots -= min(maxFreq - 1, freq[i])

        idleSlots = max(0, idleSlots)

        return len(tasks) + idleSlots