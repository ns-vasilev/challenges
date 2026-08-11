/*

1125. Smallest Sufficient Team

In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

*/

class Solution {
public:
    vector<int> smallestSufficientTeam(
        vector<string>& req_skills, 
        vector<vector<string>>& people
    ) {
        int n = req_skills.size();
        int target_mask = (1 << n) - 1;

        std::unordered_map<std::string, int> skill_map;
        for (int i = 0; i < n; ++i) {
            skill_map[req_skills[i]] = i;
        }

        int m = people.size();
        std::vector<int> person_mask = std::vector(m, 0);
        for (int i = 0; i < m; ++i) {
            for (auto skill: people[i]) {
                if (skill_map.count(skill) > 0) {
                    person_mask[i] |= (1 << skill_map[skill]);
                }
            }
        }

        std::vector<int> dp(1 << n, 1e9);
        std::vector<int> parent_mask(1 << n, -1);
        std::vector<int> parent_person(1 << n, -1);

        dp[0] = {};

        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == 1e9) continue;

            for (int i = 0; i < m; ++i) {
                if (person_mask[i] == 0) continue;

                int next_mask = mask | person_mask[i];

                if (dp[mask] + 1 < dp[next_mask]) {
                    dp[next_mask] = dp[mask] + 1;
                    parent_mask[next_mask] = mask;
                    parent_person[next_mask] = i;
                }
            }
        }

        std::vector<int> team;
        int curr = target_mask;
        while (curr > 0) {
            team.push_back(parent_person[curr]);
            curr = parent_mask[curr];
        }

        return team;
    }
};