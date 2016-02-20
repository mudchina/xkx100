// rongwutang.c 容物堂
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "容物堂");
        set("long", @LONG
这里是全真七子之二谭处端的居室，这间房间收拾的和普通的民
居没什么区别，只是一尘不染，墙上斜挂着一把宝剑。
LONG
        );
        set("exits", ([
                "north" : __DIR__"xianzhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/tan" : 1,
        ]));
	set("coor/x", -2800);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}