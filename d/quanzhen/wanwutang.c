// wanwutang.c 万物堂
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "万物堂");
        set("long", @LONG
这里是全真七子之五王处一的居所。房间不大，收拾的素雅整
洁，墙上挂着一萧一琴和一些字画，小几上摆放着宣纸和徽墨狼毫，
不知道主人是要练字还是绘画。
LONG
        );
        set("exits", ([
                "south" : __DIR__"huizhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/wangchuyi" : 1,
        ]));

	set("coor/x", -2800);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}