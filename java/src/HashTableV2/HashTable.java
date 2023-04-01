package HashTableV2;

import java.util.Random;

public class HashTable {

    TableEntry[] tableEntries;
    int insertedItems;

    public HashTable(int dimension){
        tableEntries = new TableEntry[dimension];
    }

    void insert(String key, Object value) throws Exception {
        // calcolo hash
        int hash = hash(tableEntries.length, key);
        TableEntry entry = new TableEntry(key, value);

        if(tableEntries[hash] == null){
            tableEntries[hash] = entry;
            insertedItems++;
        }else{
            // se collide cerca posto vuoto
            boolean inserted = false;
            for(int j = hash; j < tableEntries.length; j++){
                if(tableEntries[j] == null){
                    inserted = true;
                    tableEntries[j] = entry;
                    insertedItems++;
                    break;
                }
            }
            if(!inserted){
                // continua con ricerca fino a inizio (posto vuoto non trovato)
                for(int i = 0; i < hash; i++){
                    if(tableEntries[i] == null){
                        inserted = true;
                        tableEntries[i] = entry;
                        insertedItems++;
                        break;
                    }
                }
            }
            if(!inserted){
                throw new Exception("Table is full");
            }
        }

    }

    Object search(String key) throws Exception{
        int hash = hash(tableEntries.length, key);

        if(tableEntries[hash] == null){
            throw new Exception("Item not found");
        }

        TableEntry foundEntry = null;

        // controlla se è uguale o è stato spostato
        if(tableEntries[hash].compareKey(key)){
            foundEntry = tableEntries[hash];
        }else{
            // non è uguale, vai avanti con la stessa logica dell'inserimento
            boolean found = false;
            for(int j = hash; j < tableEntries.length; j++){
                if(tableEntries[j].compareKey(key)){
                    found = true;
                    foundEntry = tableEntries[j];
                    break;
                }
            }
            if(!found){
                // continua con ricerca fino a inizio (posto vuoto non trovato)
                for(int i = 0; i < hash; i++){
                    if(tableEntries[i].compareKey(key)){
                        found = true;
                        foundEntry = tableEntries[i];
                    }
                }
            }
            if(!found){
                throw new Exception("Item not found");
            }
        }

        assert foundEntry != null;
        return foundEntry.getContent();
    }

    double loadFactor(){
        return (double) insertedItems / (double) tableEntries.length;
    }

    void resize(int dimension) throws Exception {
        if(dimension < insertedItems){
            throw new Exception("New size specified too small");
        }
        // crea array con le nuove dimensioni
        TableEntry[] newTableEntries = new TableEntry[dimension];
        // effettua il rehashing di tutti gli elementi
        for (TableEntry entry: tableEntries
             ) {
            if(entry == null){
                continue;
            }
            int newHash = hash(dimension, entry.key);
            newTableEntries[newHash] = entry;
        }
        tableEntries = newTableEntries;
    }

    private static int hash(int dimension, String value){
        // converte in char array
        char[] array = value.toCharArray();
        double sum = 0;
        for(int i = 0; i < array.length; i++){
            // prendiamo il valore in int di ogni char
            int j = array[i];
            // otteniamo l'inverso della posizione
            int inv = array.length - i;
            // aggiungiamo al valore in char il seno moltiplicato per 75 di 'inv' + il valore del char a array[inv]
            double sin = Math.sin(inv + array[inv - 1] + j) * 75.0;
            // aggiungiamo tutto alla somma finale
            sum += sin;
        }
        // usiamo un random con sempre lo stesso seme per ottenere numero in range
        Random random = new Random();
        random.setSeed((long) sum);
        return random.nextInt(dimension);
    }

}
