Here you can find scripts to generate random data to test algorithm efficiency

## Usage
* Generate random `integer` numbers and save them in a file
```bash
  # Generating 100 random integer between 1 and 250 and save them in test/data/random.txt
  # I SUPPOSE THAT YOU ARE IN THE BASE OF THIS REPOSOTORY, OTHERWISE SIMPLY CHANGE THE PATHS.
  python3 dgen/intgen.py 1 250 100 test/data/random.txt
```

* Generate unique random `integer` numbers and save them in a file
```bash
  # Generating 100 unique (*without repetition*) random integer between 1 and 250 and save them in test/data/random.txt
  # I SUPPOSE THAT YOU ARE IN THE BASE OF THIS REPOSOTORY, OTHERWISE SIMPLY CHANGE THE PATHS.
  python3 dgen/intgen.py -u 1 250 100 test/data/random.txt
```
