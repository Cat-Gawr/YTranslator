
package nie.translator.rtranslator.tools.gui.peers;

import androidx.annotation.Nullable;

public class Header implements Listable {
    private String text;

    public Header(String text){
        this.text=text;
    }


    public String getText() {
        return text;
    }

    @Override
    public boolean equals(@Nullable Object obj) {
        if(obj instanceof Header){
            Header header= (Header) obj;
            return text.equals(header.getText());
        }
        return false;
    }
}
