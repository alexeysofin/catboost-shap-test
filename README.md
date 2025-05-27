# catboost-shap-test


## build & run

```bash
bash run.sh
```

## Run gdb

Enter shell

```bash
docker build -t catboost .
docker run --rm -ti catboost bash
```

Run gdb

```bash
gdb ./main
```