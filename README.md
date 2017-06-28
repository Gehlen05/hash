# hash
Por código para rodar, fazer a busca de um produto usando a primeira letra maiuscula.
Exemplo:
Azeite
Vai retornar o produto e o valor.

Foi implementado usando um vetor de listas, que cada posição do vetor endereça uma lista encadeada
referente a primeira lista do produto, em ordem alfabetica.
Para fazer a busca ele pega a primeira letra do produto desejado e manda para a lista referente,
fazendo a varredura da lista encontrando o produto se cadastrado.
A chave da hash foi utilizando a tabela ascii, para evitar conflitos de produtos começando com a letra igual. 

 
==10923== HEAP SUMMARY:                                                         
==10923==     in use at exit: 0 bytes in 0 blocks                               
==10923==   total heap usage: 145 allocs, 145 frees, 9,188 bytes allocated  