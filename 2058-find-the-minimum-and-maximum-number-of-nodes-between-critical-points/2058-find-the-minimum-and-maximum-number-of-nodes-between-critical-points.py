class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:

        first = -1
        last = -1
        prev_critical = -1

        min_dist = float('inf')

        prev = head
        curr = head.next

        index = 1

        while curr.next is not None:

            # Local maximum or local minimum
            critical = (
                (curr.val > prev.val and curr.val > curr.next.val)
                or
                (curr.val < prev.val and curr.val < curr.next.val)
            )

            if critical:

                if first == -1:
                    first = index

                if prev_critical != -1:
                    min_dist = min(
                        min_dist,
                        index - prev_critical
                    )

                prev_critical = index
                last = index

            prev = curr
            curr = curr.next
            index += 1

        # Fewer than two critical points
        if first == last:
            return [-1, -1]

        max_dist = last - first

        return [min_dist, max_dist]