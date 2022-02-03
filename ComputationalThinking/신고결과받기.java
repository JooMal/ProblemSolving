package com.test;

import java.util.*;

public class Main {

    public static void main(String[] args) {
	    // write your code here

        Solution s = new Solution();
//        String[] id_list = {"muzi", "frodo", "apeach", "neo"};
        String[] id_list = {"con", "ryan"};
//        String[] report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
        String[] report = {"ryan con", "ryan con", "ryan con", "ryan con"};
        int k = 3;

        s.solution(id_list, report, k);

        return;
    }

    static class Solution {
        public int[] solution(String[] id_list, String[] report, int k) {
            int[] answer = new int[id_list.length];

            // k번 이상 신고된 유저는 게시판 이용이 정지된다.
            // 어떤 유저가 신고한 유저가 정지되었을 경우에는 알려준다.

            Map<String, List<String>> reportMap = new HashMap<>();
            Map<String, Integer> reportedMap = new HashMap<>();

            // A가 B를 신고한 경우,
            for (String r1 : report) {
                String[] splited = r1.split(" ");
                List<String> reportList = new ArrayList<>();

                // A의 신고자 map에 B를 추가
                if (reportMap.containsKey(splited[0])) {
                    reportList = reportMap.get(splited[0]); // A의 신고 리스트
                }

                // B가 A에게 신고된 적이 있으면 유지,
                Integer cnt = 1;
                Integer reportedCnt = 0;

                // A의 신고 리스트에 B가 없다면
                if (!reportList.contains(splited[1])) {
                    // B가 신고된 횟수에 1을 추가
                    reportList.add(splited[1]);
                    reportedCnt = reportedMap.get(splited[1]);
                    if(reportedCnt == null) reportedMap.put(splited[1], 1);
                    else reportedMap.put(splited[1], reportedCnt+1);
                }
                // A의 신고 리스트에 B가 있다면(=중복 신고), 다른 동작을 하지 않는다.

                // A의 신고 리스트에 다시 reportList를 삽입한다.
                reportMap.put(splited[0], reportList);
            }

            // 메일보내기 - 1. id_list를 순회하며,
            for(int i = 0; i < id_list.length ; i++) {
                String id = id_list[i];
                List<String> reportList = reportMap.get(id);
                int cnt = 0;
                //  해당 id의 신고자 set에서
                if(reportList == null) {
                    answer[i] = 0;
                    continue;
                }
                for(String reported : reportList) {
                    if(reportedMap.containsKey(reported)) {
                        // 신고된 유저의 신고된 횟수가 k를 넘으면 cnt++
                        Integer reportedCnt = reportedMap.get(reported);
                        if(reportedCnt >= k) {
                            cnt++;
                        }
                    }
                }
                answer[i] = cnt;
            }
                // 1. id_list를 순회하며, 해당 id의 신고자 set에 있는 신고된 유저의
                // 신고됨횟수 map의 카운트가 k를 넘는지 체크 후, 넘으면 1을 더해 result에 넣는다.

            return answer;
        }
    }
}
