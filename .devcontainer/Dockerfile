FROM mcr.microsoft.com/devcontainers/base:ubuntu

# Instala gcc y make
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*