# endurance

## Docker

### Build

```sh
docker build . -t endurance
```

### Run

```sh
docker run endurance
```

### Copy Image Generated

```sh
sudo docker cp <container-id>:/usr/src/endurance/output/tree.png .
```
