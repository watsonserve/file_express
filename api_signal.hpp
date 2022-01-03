#ifndef API_SIGNAL_HPP
#define API_SIGNAL_HPP

enum ApiSignal
{
    UNKNOW = -1,
    NEW_TAB,
    CLOSE_TAB,
    SHOW_SIDE_PANEL,
    UNDO,
    REDO,
    CUT,
    COPY,
    PASTE,
    RENAME,
    DELETE,
    SELECT_ALL,
    CTX_NEW_FILE = 65,
    CTX_NEW_DIR,
    CTX_INFO,
    CTX_OPEN,
    CTX_TRASH,
    CTX_REMOVE,
    CTX_RENAME,
    CTX_CUT,
    CTX_COPY,
    CTX_PASTE,
    CTX_TERMINAL,
    CTX_CUSTOM
};

#endif // API_SIGNAL_HPP
