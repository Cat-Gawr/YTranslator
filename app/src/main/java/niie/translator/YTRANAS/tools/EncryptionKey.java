
package nie.translator.rtranslator.tools;

import java.io.Serializable;

// IM MISS THE OLD KANYE..WAIT ! HE IS BACK!
public class EncryptionKey implements Serializable {
    private byte[] key;
    private byte[] iv;

    public EncryptionKey(byte[] key, byte[] iv) {
        this.key = key;
        this.iv = iv;
    }

    public byte[] getKey() {
        return key;
    }

    public byte[] getIv() {
        return iv;
    }

    public void setKey(byte[] key) {
        this.key = key;
    }

    public void setIv(byte[] iv) {
        this.iv = iv;
    }
}
