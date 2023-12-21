-- neovide options
vim.o.guifont = "mononoki Nerd Font:h08"
vim.g.neovide_hide_mouse_when_typing = true
vim.g.neovide_input_macos_alt_is_meta = true
vim.g.neovide_hide_mouse_when_typing = false
vim.g.neovide_refresh_rate = 60
vim.g.neovide_refresh_rate_idle = 5
vim.g.neovide_no_idle = true
vim.g.neovide_confirm_quit = true
vim.g.neovide_input_use_logo = true

vim.g.neovide_cursor_antialiasing = true
vim.g.neovide_cursor_animate_in_insert_mode = true
vim.g.neovide_cursor_vfx_mode = "pixiedust"
vim.g.neovide_cursor_vfx_particle_speed = 20.0

vim.g.neovide_padding_top = 0
vim.g.neovide_padding_bottom = 0
vim.g.neovide_padding_right = 0
vim.g.neovide_padding_left = 0

-- Helper function for transparency formatting
local alpha = function()
  return string.format("%x", math.floor(255 * (vim.g.transparency or 0.98)))
end
vim.g.neovide_transparency = 0.98
vim.g.transparency = 0.98
vim.g.neovide_background_color = "#1d2021" .. alpha()

-- nvim options
vim.opt.shiftwidth = 4
vim.opt.tabstop = 4
vim.opt.relativenumber = true
vim.cmd('autocmd FileType markdown setlocal nospell')
vim.opt.wrap = true -- wrap lines
vim.opt.spell = false
vim.o.shell = '/usr/bin/bash'
vim.o.autochdir = true
vim.cmd('autocmd BufEnter * lcd %:p:h')

-- general
lvim.use_icons = true
lvim.log.level = "info"
lvim.format_on_save = {
  enabled = true,
  pattern = "*.lua",
  timeout = 1000,
}

-- change theme settings
lvim.colorscheme = "gruvbox"
lvim.transparent_window = false
lvim.builtin.alpha.active = true
lvim.builtin.alpha.mode = "dashboard"
lvim.builtin.terminal.active = true
lvim.builtin.nvimtree.setup.view.side = "left"
lvim.builtin.nvimtree.setup.renderer.icons.show.git = false

-- automatically install missing parsers when entering buffer
lvim.builtin.treesitter.auto_install = true

-- additional Plugins
lvim.plugins = {
  { "lunarvim/colorschemes" },
  { "ellisonleao/gruvbox.nvim" },
  { "puremourning/vimspector" },
  { "SirVer/ultisnips" },
  { "CRAG666/code_runner.nvim" },
}

-- configuring colorscheme
require("gruvbox").setup({
  undercurl = true,
  underline = true,
  bold = false,
  italic = {
    strings = true,
    comments = true,
    operators = false,
    folds = true,
  },
  strikethrough = true,
  invert_selection = false,
  invert_signs = false,
  invert_tabline = false,
  invert_intend_guides = false,
  inverse = true,    -- invert background for search, diffs, statuslines and errors
  contrast = "hard", -- can be "hard", "soft" or empty string
  palette_overrides = {},
  overrides = {},
  dim_inactive = false,
  transparent_mode = false,
})

-- vimspector options
vim.g.vimspector_enable_mappings = 'HUMAN'
vim.g.vimspector_enable_mappings_for_mode = {
  ['<leader><leader>'] = { 'n', 'v' },
}

-- code runner options
require('code_runner').setup({
  filetype = {
    java = {
      "cd $dir &&",
      "javac $fileName &&",
      "java $fileNameWithoutExt"
    },
    python = "python3 -u",
    typescript = "deno run",
    rust = {
      "cd $dir &&",
      "rustc $fileName &&",
      "$dir/$fileNameWithoutExt"
    },
    cs = {
      "cd '$dir' &&",
      "dotnet run"
    }
  },
})

lvim.keys.normal_mode["<leader>r"] = ":RunCode<CR>"
lvim.keys.normal_mode["<leader>rf"] = ":RunFile<CR>"
lvim.keys.normal_mode["<leader>rft"] = ":RunFile tab<CR>"
lvim.keys.normal_mode["<leader>rp"] = ":RunProject<CR>"
lvim.keys.normal_mode["<leader>rc"] = ":RunClose<CR>"
lvim.keys.normal_mode["<leader>crf"] = ":CRFiletype<CR>"
lvim.keys.normal_mode["<leader>crp"] = ":CRProjects<CR>"
