# Imagem base: minima
FROM ubuntu:18.04

# Variável de ambiente pra codificação
ENV LANG=C.UTF-8

# Instalando pacotes necessários
RUN apt-get update \
    && apt-get install -y flex g++ make \
    && rm -rf /var/lib/apt/lists/*

# Copiando arquivos fonte
COPY . /usr/src/endurance
WORKDIR /usr/src/endurance

RUN make

# Roda o Make por padrão
CMD ["bash", "./run.sh"]