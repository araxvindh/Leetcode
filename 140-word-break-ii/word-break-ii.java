class Solution {
    public static void wordBreak1(List<String> words, String str, List<String> res, String output, int start) {
        if (start == str.length()) {
            res.add(output.trim());
            return;
        }

        for (int i = start; i < str.length(); i++) {
            String word = str.substring(start, i + 1);

            if (words.contains(word)) {
                wordBreak1(words, str, res, output + word + " ", i + 1);
            }
        }
    }

    public List<String> wordBreak(String str, List<String> words) {

        List<String> res = new ArrayList<>();

        wordBreak1(words, str, res, "", 0);

        return res;
    }
}