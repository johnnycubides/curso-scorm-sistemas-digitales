# Proyectos realizados con Litex y Softcore
_Repositorio para el desarrollo de proyectos de LITEX y Softcores mediante herramientas `Open-Source` para el diseño, implementación y pruebas._

## Comenzando 🚀
Estas instrucciones le permitirán obtener una copia del proyecto en funcionamiento en su máquina local para propósitos de desarrollo y pruebas.

### Estructura del repositorio
Se espera que la rama **Master** sea para cargar los toolchains y las fuentes de cada proyecto de manera ordenada y probada. Para clonar el repositorio basta ejecutar los siguientes comandos en una terminal:

```
mkdir dir-local-del-repo
$git clone https://github.com/unal-digital-electronic/litex-and-softcore-projects.git dir-local-del-repo/
$cd dir-local-del-repo
```

Para el desarrollo de nuestros proyectos y herramientas se recomienda manejar branchs distintos para **dev-cl-5a-75e-examples**, **dev-openocd-tool**, **dev-tools** y por supuesto **master**, cuando tengan un nivel de desarrollo pertinente se podrán mezclar a la rama principal mediante el uso de `merge`. Para tener disponibles estas ramas localmente siga estos pasos:

- Liste las ramas del repositorio:
```
$ git branch
*master
```
- Las ramas ocultas pueden listarse mediante el argumento `-a`
```
$ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/dev-cl-5a-75e-examples
  remotes/origin/dev-openocd-tool
  remotes/origin/dev-tools
  remotes/origin/master
```
- Para obtener localmente las ramas listadas, use: (No es estrictamente necesario, pero aprenderá el manejo de ramas)
```
$ git checkout dev-cl-5a-75e-examples
$ git checkout dev-openocd-tool
$ git checkout dev-tools
```
_**NOTA:** Recuerde que para moverse entre ramas puede usar el comando `$ git checkout <nombre-branch>`._

- Liste de nuevo las ramas del repositorio:
```
$ git checkout master # Para ubicarnos en la rama principal
$ git branch
  dev-cl-5a-75e-examples
  dev-openocd-tool
  dev-tools
* master
```
### Crear una rama de trabajo propia

Adicionalmente se debe crear una rama propia para el desarrollo individiual (con configuraciones, ejemplos, etc.)  de cada desarrollador. Para crear una propia rama apartir de otra (desde `master`) ejecute:
```
$ git checkout master # Asegurese de estar en la rama principal, a partir de esta creará su propia rama
$ git checkout -b <nombre-de-su-rama> # Nombre su rama, ejemplo nelsont, johnnyc.
Switched to a new branch 'nombre-de-su-rama'
```
Ahora verá que tiene los mismos archivos que master, estos son el punto de partida de su rama y serán completamente independientes. Procure siempre verificar que se encuentre trabajando en su rama (use `$ git checkout <nombre-de-su-rama>` para hacerlo).

- Crear un remoto para subir archivos a la nube (mediante `git push`)
Para darle un nombre a un remoto use la forma ` git remote add <nombre-remoto> <url-remoto>` (No es estrictamente necesario, tambien puede usar `origin` por defecto): 

```
$ git remote add curso-dir https://github.com/unal-digital-electronic/litex-and-softcore-projects.git
$ git remote -v
curso-dir	https://github.com/unal-digital-electronic/litex-and-softcore-projects.git (fetch)
curso-dir	https://github.com/unal-digital-electronic/litex-and-softcore-projects.git (push)
origin	https://github.com/unal-digital-electronic/litex-and-softcore-projects.git (fetch)
origin	https://github.com/unal-digital-electronic/litex-and-softcore-projects.git (push)
```
- Haga cambios en los archivos de su rama, por ejemplo en el `README.md` y haga commits a su rama. Para ello siga la secuencia `git add`, `git commit` y `git push`:

1. Seguimiento de archivos: 
Use `git status` para saber que archivos han sido modificados, eliminados o creados, y se pueden añadir a un próximo commit.
```
$ git status
On branch nelsont
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   README.md

no changes added to commit (use "git add" and/or "git commit -a")
```
2. Añada los archivos:
```
$ git add README.md      # Solo el README.md
```
ó
```
$ git add .              #Todos los archivos
```
3. Haga commit incluyendo un mensaje:
```
$ git commit -m "Mensaje-del-commit"
[nelsont 83abcbf] Mensaje-del-commit
 1 file changed, 3 insertions(+), 1 deletion(-)
```
4. Suba el commit al repositorio remoto y a **su rama** mediante `git push <nombre-del-remoto> <rama-destino>`:
```
$ git push curso-dir nelsont
Username for 'https://github.com': nelsontovar32       # Ingrese el usuario de Github
Password for 'https://nelsontovar32@github.com':       # Ingrese la contraseña
Counting objects: 3, done.
Delta compression using up to 8 threads.
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 400 bytes | 400.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
remote: 
remote: Create a pull request for 'nelsont' on GitHub by visiting:
remote:      https://github.com/unal-digital-electronic/litex-and-softcore-projects/pull/new/nelsont
remote: 
To https://github.com/unal-digital-electronic/litex-and-softcore-projects.git
 * [new branch]      nelsont -> nelsont
```
Ahora la rama de cada uno está disponible para que todos puedan verla ú obtenerla localmente.

### Traer archivos de una rama a otra
Esto será útil cuando deseemos traer directorios o archivos especificos que han sido desarrollados por otras personas (ó nosotros mismos) en otras ramas a nuestra rama de trabajo.
Por ejemplo, de la rama `dev-cl-5a-75e-examples` queremos traer a nuestra rama el directorio que contiene el último ejemplo subido (`litex-vexriscv-blink`).

- Actualizar (ó ubicarse en el commit respectivo) la rama desde donde se desean traer ficheros o directorios:
```
$ git checkout dev-cl-5a-75e-examples
Switched to branch 'dev-cl-5a-75e-examples'
Your branch is up to date with 'origin/dev-cl-5a-75e-examples'.
```
En caso de no estar actualizada, haga un pull: `git pull <nombre-del-remoto> dev-cl-5a-75e-examples`

- Ubique el fichero o directorio, en este caso la carpeta `cl-5a-75e-project-example/litex-vexriscv-blink/` y copie esa ruta. **Nota:** Trabaje desde la raiz de cada rama y no en subdirectorios.

- Ubíquese en la rama de destino, en este caso la rama personal de trabajo:
```
$ git checkout <nombre-de-su-rama>
Switched to branch 'nombre-de-su-rama'
```
- Utilice `git checkout <rama-origen> <path-completo-directorio>` para traer el directorio de la siguiente forma:
```
$ git checkout dev-cl-5a-75e-examples cl-5a-75e-project-example/litex-vexriscv-blink/     #Copiará ese directorio en la misma ruta pero en la nueva rama.
$ git status
On branch nelsont
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)
	new file:   litex-vexriscv-blink/.gitignore
        ...
```
- Ya tiene el nuevo directorio y este se encuentra en seguimiento automaticamente, finalmente haga un `commit` (y `push` si lo desea):
```
$ git commit -m "Ejemplo-Litex traido desde rama de ejemplos"
```