" Fuente: https://github.com/dense-analysis/ale/issues/1616
"There's a way: project-specific vimrc. It goes nicely with project-specific tags, .ctagsignore and any .clang-format you have in your project.

" Add to .vimrc to enable project-specific vimrc

" set exrc
" set secure

" exrc allows loading local executing local rc files.
" secure disallows the use of :autocmd, shell and write commands in local .vimrc files.

"Then, in a new .vimrc in your project directory (or .nvimrc for neovim), add this:

" let g:ale_c_clang_options="-L./src -I./include"
" let g:ale_cpp_clang_options="-L./src -I./include"

" project
" let includeFiles = ""
" let includeFiles .= ""

"************************************************************************
"" Keyboards short cut
"************************************************************************
nnoremap <F1> :echo MyMenuFuntions()<CR>
" nnoremap <silent> <F5> :ALEDetail<CR>
nnoremap <silent> <F5> :mak! lb<CR>
nnoremap <silent> <F6> :call ToggleCopenCclose()<CR>
nnoremap <silent> <F7> :ALEDetail<CR>
" nnoremap <silent> <F6> :call ToggleCopenCclose()<CR>
" nnoremap <silent> <F8> :make s<CR>
nnoremap <silent> <F8> :call ToggleColorScheme()<CR>
" unmap <F9>
" unmap! <F9>
" nnoremap <F9> :call ToggleCopenCclose()<CR>
nnoremap <silent> <F10> :bd<CR>
" nnoremap <silent> <F9> :bd<CR>


" More functions
let mapleader=','
noremap <leader>j :ALENext<CR>


let g:coc = 1
function ToggleCopenCclose()
if g:coc == 1
:copen
let g:coc = 0
else
:cclose
let g:coc = 1
endif 
endfunction

" Cambio de color_scheme_user
let g:color_scheme_user = 1 " user var
function! ToggleColorScheme()
if g:color_scheme_user == 1
    :colorscheme morning
    let g:color_scheme_user = 2
elseif g:color_scheme_user == 2
    :colorscheme monokai
    let g:color_scheme_user = 3
elseif g:color_scheme_user == 3
    :colorscheme molokai
    let g:color_scheme_user = 0
else
    :colorscheme murphy
    let g:color_scheme_user = 1
endif
endfunction

function MyMenuFuntions()
  let out = "Menu de Funciones:\n"
  let out .= " F1: Ver éste menú\n F2: Ubicación de archivo cargado en el buffer\n F3: Abrir NERDTree\n F4: TagBar\n"
  " let out .= " F6: copen/cclose registro de errores y advertencias al compilar\n"
  " let out .= " F5: Compilar (make lb)\n"
  let out .= " F6: Toggle copen cclose\n"
  " let out .= " F7: Check detalles de errores C, C++\n"
  " let out .= " F9: Close buffer\n"
  let out .= " F9: Toggle colorscheme\n"
  let out .= " F10: Close buffer\n"
  let out .= " F11: Toggle colorscheme\n"
  let out .= " ,j: ALENext\n ,k: ALEPrevious\n"
  return out
endfunction

" autocmd FileType vue setlocal tabstop=2 shiftwidth=2 expandtab
" call CodeTab2()
call Es()
set autowrite!
