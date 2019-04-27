import java.util.Stack;

public class DecodeString {
    public String decodeString(String s) {
        Stack<String> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ']') {
                String str = "";
                while (!st.peek().equals("[")) {
                    str = st.pop() + str;
                }
                st.pop();

                String countStr = "";
                while (!st.empty() && Character.isDigit(st.peek().charAt(0))) {
                    countStr = st.pop() + countStr;
                }
                int count = Integer.parseInt(countStr);
                String newStr = "";
                for (int j = 0; j < count; j++) {
                    newStr += str;
                }
                st.push(newStr);
            } else {
                st.push("" + s.charAt(i));
            }
        }

        String str = "";
        while (!st.empty()) {
            str = st.pop() + str;
        }

        return str;
    }
}
