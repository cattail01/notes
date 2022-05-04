import java.util.List;
import java.util.Map;

public class Test {
	public static void main(String[] args) {
		List<Map<String,String>>lst;
		StudentClass xg = new StudentClass();
		xg.createClass();
		lst=xg.formateStudent();
		try {
			FileOperation xgStudent=new FileOperation("student.txt");
			xgStudent.save(lst);
			xgStudent.close();
			System.out.println("success");
		}
		catch(Exception e) {
			System.out.println("error");
		}
	}
}
