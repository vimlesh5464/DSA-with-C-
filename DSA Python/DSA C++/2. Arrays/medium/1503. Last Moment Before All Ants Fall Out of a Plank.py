# 1503. Last Moment Before All Ants Fall Out of a Plank.py - Python skeleton converted from C++

# Original C++ code:
# // We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. Some of the ants move to the left, the other move to the right.
# 
# // When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.
# 
# // When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.
# 
# // Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.
# 
#  
# 
# // Example 1:
# 
# // Input: n = 4, left = [4,3], right = [0,1]
# // Output: 4
# // Explanation: In the image above:
# // -The ant at index 0 is named A and going to the right.
# // -The ant at index 1 is named B and going to the right.
# // -The ant at index 3 is named C and going to the left.
# // -The ant at index 4 is named D and going to the left.
# // The last moment when an ant was on the plank is t = 4 seconds. After that, it falls immediately out of the plank. (i.e., We can say that at t = 4.0000000001, there are no ants on the plank).
# 
# // Example 2:
# 
# // Input: n = 7, left = [], right = [0,1,2,3,4,5,6,7]
# // Output: 7
# // Explanation: All ants are going to the right, the ant at index 0 needs 7 seconds to fall.
# 
# // Example 3:
# 
# // Input: n = 7, left = [0,1,2,3,4,5,6,7], right = []
# // Output: 7
# // Explanation: All ants are going to the left, the ant at index 7 needs 7 seconds to fall.
# 
#  
# 
# // Constraints:
# 
# //     1 <= n <= 104
# //     0 <= left.length <= n + 1
# //     0 <= left[i] <= n
# //     0 <= right.length <= n + 1
# //     0 <= right[i] <= n
# //     1 <= left.length + right.length <= n + 1
# //     All values of left and right are unique, and each value can appear only in one of the two arrays.
# 
#  
# // Seen this question in a real interview before?
# // 1/5
# // Yes
# // No
# // Accepted
# // 98,976/145.1K
# // Acceptance Rate
# // 68.2%
# // Topics
# // Senior
# // Array
# // Brainteaser
# // Simulation
# // Weekly Contest 196
# // icon
# // Companies
# // Hint 1
# // The ants change their way when they meet is equivalent to continue moving without changing their direction.
# // Hint 2
# // Answer is the max distance for one ant to reach the end of the plank in the facing direction.
# // Similar Questions
# // Count Collisions on a Road
# // Medium
# // Movement of Robots
# // Medium
# // Discussion (92)
# // 💡 Discussion Rules
# 
# // 1. Please don't post any solutions in this discussion.
# 
# // 2. The problem discussion is for asking questions about the problem or for sharing tips - anything except for solutions.
# 
# // 3. If you'd like to share your solution for feedback and ideas, please head to the solutions tab and post it there.
# // gridZ
# // Dec 25, 2021
# 
# // ...i'm pretty sure it's a banned question at alphabet and probably a few other places since it's so popular.
# // the key insight is that the collision rule doesn't matter at all, the effect is the same as if the ants just phased through each other. once you realize it, the easy solution becomes obvious.
# // i don't like this type of questions very much. it hinges on one epiphany and there's no way to dig deeper or expand the discussion, doesn't tell me a lot about candidate's actual skills or thinking. i wouldn't ask it in an interview and getting it in an interview would be a negative sign for me personally.
#  
# // 131
# // Show 5 Replies
# // Reply
# // Diwanshu Kumar
# // 100 Days Badge 2025
# // Nov 04, 2023
# 
# // Looks like Leetcode has removed the dislike button.
# 
# // Edit : They bring back the dislike button, but still it doesn't show the count so not useful for us.
#  
# // 83
# // Show 6 Replies
# // Reply
# // Haver Of Name
# // LeetCode 75
# // Nov 04, 2023
# 
# // This question tests whether you have seen this puzzle before or not, doesn't test programming skills.
#  
# // 56
# // Show 3 Replies
# // Reply
# // Saad Waseem
# // Annual Badge 2023
# // Nov 04, 2023
# 
# // Kidney touching question
#  
# // 51
# // Reply
# // atharva598
# // Jun LeetCoding Challenge
# // Jun 13, 2023
# 
# // Good problem, but they need to replace the depiction of the ants with a simple arrow. The current depiction only causes confusion about their direction.
#  
# // 45
# // Show 3 Replies
# // Reply
# // An-Wen Deng
# // 200 Days Badge 2024
# // Nov 04, 2023
# 
# // I don't like this description. If you use a moving ball instead, it just reflects the physics. The same trick can be applied for the much harder problem 2731. Movement of Robots
#  
# // 24
# // Show 2 Replies
# // Reply
# // sroninio
# // 50 Days Badge 2022
# // Nov 24, 2021
# 
# // ants dont really change direction when the crash, each one keeps moving forward (we dont care that they changed names, they are still ants :-))
#  
# // 34
# // Reply
# // Yi Jiang
# // 500 Days Badge
# // Nov 04, 2023
# 
# // I don't understand why there're so many complaints. What exactly are the "skills" that you are looking for?
# // I once wasn't able to solve an integration problem in a Calculus test, and I lost a lot of points. Later, I learned that the result to the difficult part that I wasn't able to integrate, is zero, because it was an odd function and the positive and negative part cancels out. Should I go to the teacher and tell them "This is a bad question, it doesn't test my integration skills at all!" ?
# // Just be glad that you learned a new trick today, so you'll be able to solve similar problems in the future.
# // Or keep complaining, like that'll do you any good :)
# 
# // (PS: Or, you can be like von Neumann.
# // Maybe relevant story:)
# 
# //     Then there is the famous fly puzzle. Two bicyclists start twenty miles apart and head toward each other, each going at a steady rate of 10 m.p.h. At the same time a fly that travels at a steady 15 m.p.h. starts from the front wheel of the southbound bicycle and flies to the front wheel of the northbound one, then turns around and flies to the front wheel of the southbound one again, and continues in this manner till he is crushed between the two front wheels. Question: what total distance did the fly cover? When the question was put to von Neumann, he solved it in an instant, and thereby disappointed the questioner: "Oh, you must have heard the trick before!" "What trick?" asked von Neumann; "all I did was sum the infinite series."
# 
#  
# // Read more
# // 33
# // Show 2 Replies
# // Reply
# // Amit Dahiya
# // 500 Days Badge
# // Nov 04, 2023
# 
# // Hints :
# // 1 - > Ignore the thing that they will change direction
# // 2 -> In ants going to left rightmost will fall last from 0th end
# // 3-> In ants going to right leftmost will fall last from nth end
# // Note :- No ants were harmed in the collisions !! They just need parachutes for jump
#  
# // 25
# // Show 2 Replies
# // Reply
# // abinitio
# // Feb LeetCoding Challenge
# // Nov 04, 2023
# 
# // 🎃👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻👻🎃
# // Hint 1: What if the ants were ghosts? (They would be able to pass through each other without blocking.)
# // Hint 2: Would the behavior of ghost ants differ from that of physical ants?
# // 🎃🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🐜🎃
#  
# // Tip
# // 14
# // Show 1 Replies
# // Reply
# // Copyright © 2026 LeetCode. All rights reserved.
# 
# #include <iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       int getLastMoment(int n, vector<int>& left, vector<int>& right) {
#           int t =0;
#           for(int i = 0; i < left.size(); i++){
#               t = max(t,left[i]);
#           }
#           for(int i =0; i < right.size(); i++){
#               t = max(t,n-right[i]);
#           }
#           return t;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
