````md
# Projeto PBL Fase 3 — Banco de Dados Oracle

## Integrantes
- Viktor Ribeiro Dos Santos Cunha — RM570917
---

# Objetivo

O objetivo deste projeto foi importar os dados coletados pelos sensores da Fase 2 para um banco de dados Oracle utilizando o Oracle SQL Developer.

Após a importação, foram realizadas consultas SQL para validação e exploração dos dados armazenados.

---

# Tecnologias Utilizadas

- Oracle SQL Developer
- Oracle Database
- SQL
- GitHub

---

# Passo a Passo Executado

## 1. Instalação do Oracle SQL Developer

Foi realizado o download do Oracle SQL Developer através do site oficial da Oracle.

---

## 2. Configuração da Conexão

Foram utilizados os seguintes dados:

- Host: oracle.fiap.com.br
- Porta: 1521
- SID: ORCL
- Usuário: RMXXXXX
- Senha: DDMMYY

### Print da conexão

![Conexão Oracle](prints/conexao_oracle.png)

---

## 3. Importação dos Dados

Os dados coletados pelos sensores foram importados através da opção:

```text
Tabelas (Filtrado) → Importar Dados
```

A tabela criada recebeu o nome:

```sql
SENSORES_AGRO
```

### Print da importação

![Importação](prints/importacao_dados.png)

---

## 4. Consulta SQL

Após a importação, foi realizada uma consulta SQL para validar os dados armazenados.

```sql
SELECT * FROM SENSORES_AGRO;
```

### Print da consulta

![Consulta SELECT](prints/select_all.png)

---

# Consultas SQL Realizadas

## Quantidade de registros

```sql
SELECT COUNT(*) FROM SENSORES_AGRO;
```

---

## Média de umidade

```sql
SELECT AVG(UMIDADE) FROM SENSORES_AGRO;
```

---

## Média de temperatura

```sql
SELECT AVG(TEMPERATURA) FROM SENSORES_AGRO;
```

---

## Maior temperatura registrada

```sql
SELECT MAX(TEMPERATURA) FROM SENSORES_AGRO;
```

---

## Menor temperatura registrada

```sql
SELECT MIN(TEMPERATURA) FROM SENSORES_AGRO;
```

---

### Print das consultas SQL

![Consultas SQL](prints/consultas_sql.png)

---

# Estrutura do Projeto

```text
farmtech-pbl-fase3/
│
├── README.md
├── dados/
│   └── sensores.csv
├── prints/
│   ├── conexao_oracle.png
│   ├── importacao_dados.png
│   ├── select_all.png
│   └── consultas_sql.png
└── video/
    └── link_video.txt
```

---

# Conclusão

Foi possível importar os dados coletados pelos sensores para o banco Oracle e realizar consultas SQL para exploração e validação das informações.

O projeto permitiu compreender conceitos básicos de banco de dados relacionais, manipulação de tabelas e execução de consultas SQL aplicadas ao agronegócio.

---

# Vídeo Demonstrativo

Link do vídeo disponível em:

```text
video/link_video.txt
```
````
