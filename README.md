### CorePad
//
### English version
//
//
## CorePad was developed as a simple notepad in c++ using the libaries:
//
# (iostream, string and fstream)
//
## add corepad.h to "C:/MinGW/include" !!!
//
## don't forget to add a debugger in vscode c_cpp_properties_json added to "includePath": ["${workspaceFolder}/**"] the path "C:/MinGW/include" for it to understand corepad.h !!!
//
## Corepad commands
//
# Use Core_comands(); to see corepad commands
//
//
### Versão em Português
//
//
## O CorePad foi desenvolvido como um projeto simples de bloco de notas no c++ usando as bibliotecas:
//
# (iostream, string e fstream)
//
## adicionar o corepad.h ao "C:/MinGW/include" !!!
//
## não se esqueça de adicionar um debuguer no vscode c_cpp_properties_json adicionado ao "includePath": ["${workspaceFolder}/**"] o caminho "C:/MinGW/include" para ele entender o corepad.h !!!



## Comandos do corepad

# Usar Core_comands(); para ver os comandos do corepad
def ler_e_converter_binario(arquivo):
    try:
        with open(arquivo, 'rb') as f:
            conteudo = f.read()  # Lê o conteúdo do arquivo binário
        
        texto_convertido = ""
        
        for byte in conteudo:
            # Se o byte for imprimível (entre 32 e 126 no ASCII)
            if 32 <= byte <= 126:
                texto_convertido += chr(byte)
            else:
                # Para bytes não imprimíveis, colocamos um ponto
                texto_convertido += '.'
        
        # Verifica se o conteúdo convertido é vazio, caso sim, retorna "Arquivo vazio ou não legível"
        if not texto_convertido.strip():
            return "Arquivo vazio ou não legível"
        
        return texto_convertido
    
    except Exception as e:
        return f"Erro ao ler o arquivo: {e}"

# Exemplo de uso
arquivo_binario = 'exemplo.txt'  # Altere para o caminho do seu arquivo .txt ou outro
resultado = ler_e_converter_binario(arquivo_binario)
print(resultado)