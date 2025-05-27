
package nie.translator.rtranslator.tools.gui.peers.array;

import nie.translator.rtranslator.tools.gui.peers.Listable;

public interface PeerListArray {

    boolean add(Listable guiPeer);

    void set(int index, Listable newPeer);

    Listable get(int index);

    int size();

    int indexOf(Listable guiPeer);

    boolean remove(Listable guiPeer);

    void clear();
}
