
package nie.translator.rtranslator.tools.gui.peers;

import android.bluetooth.BluetoothDevice;
import android.graphics.Bitmap;
import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.Nullable;

import java.io.ByteArrayOutputStream;

import nie.translator.rtranslator.tools.Tools;
import nie.translator.rtranslator.bluetooth.Peer;

public class GuiPeer extends Peer implements Listable {
    private byte[] userImage;

    public GuiPeer(Peer peer, @Nullable Bitmap userImage) {
        super(peer);
        if (userImage != null) {
            ByteArrayOutputStream stream = new ByteArrayOutputStream();
            userImage.compress(Bitmap.CompressFormat.PNG, 100, stream);
            this.userImage = stream.toByteArray();
        }
    }

    public GuiPeer(BluetoothDevice device, String uniqueName, boolean isConnected) {
        super(device, uniqueName, isConnected);
    }

    public GuiPeer(BluetoothDevice device, String uniqueName, boolean isConnected, @Nullable Bitmap userImage) {
        super(device, uniqueName, isConnected);
        if (userImage != null) {
            ByteArrayOutputStream stream = new ByteArrayOutputStream();
            userImage.compress(Bitmap.CompressFormat.PNG, 100, stream);
            this.userImage = stream.toByteArray();
        }
    }

    public GuiPeer(BluetoothDevice device, String uniqueName, boolean isConnected, @Nullable byte[] userImage) {
        super(device, uniqueName, isConnected);
        this.userImage = userImage;
    }

    public Bitmap getUserImage() {
        if (userImage != null) {
            return Tools.convertBytesToBitmap(userImage);
        } else {
            return null;
        }
    }

    public byte[] getUserImageData() {
        return userImage;
    }

    public void setUserImage(Bitmap userImage) {
        if (userImage != null) {
            ByteArrayOutputStream stream = new ByteArrayOutputStream();
            userImage.compress(Bitmap.CompressFormat.PNG, 100, stream);
            this.userImage = stream.toByteArray();
        } else {
            this.userImage = null;
        }
    }

    //parcelable implementation
    public GuiPeer(Parcel in) {
        super(in);
        in.readByteArray(userImage);
    }

    public static final Parcelable.Creator<GuiPeer> CREATOR = new Parcelable.Creator<GuiPeer>() {
        @Override
        public GuiPeer createFromParcel(Parcel in) {
            return new GuiPeer(in);
        }

        @Override
        public GuiPeer[] newArray(int size) {
            return new GuiPeer[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int i) {
        super.writeToParcel(parcel, i);
        parcel.writeByteArray(userImage);
    }
}
