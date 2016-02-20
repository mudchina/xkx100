// fu-datang 富家大堂
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "富家大堂");
        set("long", @LONG
这里是侯员外家的大堂，堂梁上挂着一块匾(bian)。堂内摆
放着一些八仙桌和椅子，堂壁上梅兰竹菊的竹帘被挂成了兰竹菊
梅，看来这家也不过是附庸风雅的暴发户而已。
LONG
        );
        set("exits", ([
                "east" : __DIR__"fu-ceting",
                "west" : __DIR__"fu-zhangfang",
                "north" : __DIR__"fu-xiaoyuan",
                "south" : __DIR__"fu-houyuan",
        ]));
        set("item_desc", ([
           "bian": HIR"
＃＃＃＃＃＃＃＃＃＃＃＃＃
＃＃　　　　　　　　　＃＃
＃＃　忠　义　传　家　＃＃
＃＃　　　　　　　　　＃＃
＃＃＃＃＃＃＃＃＃＃＃＃＃
"NOR
        ]) );
        set("no_clean_up", 0);
	set("coor/x", -3130);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}