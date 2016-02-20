// houtang3.c 后堂三进
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后堂三进");
        set("long", @LONG
这里是全真教弟子演练武功的地方。全真教弟子众多，所以每逢
每月的十五这天，就召集所有弟子来这里切磋武功，一方面检验弟子
们的武功长进，另一方面选拔人才担任教中的重要职务。现在还不到
演武的日子，堂中空无一人。
LONG
        );
//        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"jingxiushi",
                "west" : __DIR__"houtang2",
                "northeast" : __DIR__"xiaohuayuan1",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/wangzhitan" : 1,
        ]));

	set("coor/x", -2740);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}