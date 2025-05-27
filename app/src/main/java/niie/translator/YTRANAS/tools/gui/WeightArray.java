
package nie.translator.rtranslator.tools.gui;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class WeightArray {
    private ArrayList<WeightElement> array;

    public WeightArray() {
        array= new ArrayList<>();
    }

    public WeightArray(@NonNull Collection<? extends WeightElement> c) {
        array= new ArrayList<>(c);
    }

    public boolean add(WeightElement weightElement) {
        boolean ret = array.add(weightElement);
        Collections.sort(array);
        return ret;
    }

    public WeightElement set(int index, WeightElement element) {
        WeightElement ret = array.set(index, element);
        Collections.sort(array);
        return ret;
    }

    public WeightElement get(int index){
        return array.get(index);
    }

    public int size(){
        return array.size();
    }

    public boolean remove(@Nullable WeightElement o) {
        boolean ret = array.remove(o);
        Collections.sort(array);
        return ret;
    }

    public int indexOf(WeightElement o){
        return array.indexOf(o);
    }
}
