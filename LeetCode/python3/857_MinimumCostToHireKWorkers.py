"""
857. Minimum Cost to Hire K Workers
Hard

566

60

Favorite

Share
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.



Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately.


Note:

1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.
"""

"""
关键点 按照性价比最低的工人对应的效率发工资，所以要对w/q进行排序，取最大w/q作为当前的工资标准（当前位置以前的w/q都小于当前，所以以当前为标准，发的工资就符合要求）
"""
"""
Runtime: 232 ms, faster than 19.96% of Python3 online submissions for Minimum Cost to Hire K Workers.
Memory Usage: 16.4 MB, less than 9.09% of Python3 online submissions for Minimum Cost to Hire K Workers.
"""
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        workers=sorted([(q,w/q) for q,w in zip(quality,wage)],key=lambda x:x[1])
        queue=[]
        qsum=0
        res=float('inf')
        for q,rate in workers:
            heapq.heappush(queue,-q)
            qsum+=q
            if len(queue)>K:
                qsum+=heapq.heappop(queue)
            if len(queue)==K:
                res=min(res,qsum*rate)
        return res
