import java.io.File;
import java.io.FileOutputStream;

public class test_write  {
	public void DOWriteTxt(String file, String txt) {
		try{
			FileOutputStream os = new FileOutputStream(new File(file), true);
			os.write((txt + "\n").getBytes());
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		 int i = 0;
		 for(i = 0; i < 1000000; i++){
			 new test_write().DOWriteTxt("file.java", "ddddffddddd");
		 }
	}
}
