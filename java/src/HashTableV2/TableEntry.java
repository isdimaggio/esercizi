package HashTableV2;

public class TableEntry {

    String key;
    Object content;

    public TableEntry(String key, Object content) {
        this.key = key;
        this.content = content;
    }

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public Object getContent() {
        return content;
    }

    public void setContent(Object content) {
        this.content = content;
    }

    public boolean compareKey(String key) {
        return this.key.equals(key);
    }

}
