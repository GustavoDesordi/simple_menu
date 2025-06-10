cmake_minimum_required(VERSION 3.10)

# Nome do projeto e padrão C
project(SistemaVendas C)

# Define o padrão C
set(CMAKE_C_STANDARD 99)

# Adiciona os arquivos-fonte
add_executable(SistemaVendas
        main.c
        src/cliente/cliente.c
        src/produto/produto.c
)