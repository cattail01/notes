import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Map;

public class FileOperation {
	private FileWriter out;
	public FileOperation(String fileName) throws IOException {
		out = new FileWriter(fileName);
	}
	public void save(List<Map<String,String>>lst) throws IOException {
		for(Map<String,String>m : lst) {
			for(Map.Entry entry:m.entrySet()) {
				out.write(entry.getKey()+":"+entry.getValue()+"\t");
			}
			out.write("\r\n");
		}	
	}
	public void close() throws IOException{
		out.close();
	}
}
