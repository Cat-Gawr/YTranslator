
package nie.translator.rtranslator.tools;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**Not used**/
public class FileManager {
    private File directory;

    public FileManager(File directory){
        this.directory= directory;
    }

    public Object getObjectFromFile(String fileName, Object defValue){
        File file = new File(directory, fileName);
        Object object=defValue;

        if(file.exists() && file.canRead()){
            try {
                ObjectInputStream objectInputStream= new ObjectInputStream(new FileInputStream(file));
                object= objectInputStream.readObject();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

        return object;
    }

    public void setObjectInFile(String fileName,Object object){
        File file = new File(directory, fileName);

        try {
            ObjectOutputStream objectOutputStream= new ObjectOutputStream(new FileOutputStream(file));
            objectOutputStream.writeObject(object);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
