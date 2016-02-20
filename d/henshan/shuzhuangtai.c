// Room: /d/henshan/shuzhuangtai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "梳妆台");
        set("long", @LONG
藏经殿有一泓碧泉如镜，向称美容泉。相传为南陈后主妃在此避乱
时，对碧水照容颜梳妆打扮的地方。殿前胜迹有灵日，昔时夜间常见飞
光，或如繁星点点，或若万萤乱飞，煞是壮观。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "north"   : __DIR__"cangjingdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1020);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
