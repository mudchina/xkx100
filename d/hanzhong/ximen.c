// ximen.c 西门
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "西门");
        set("long", @LONG
这里是汉中镇的西门，眼前城墙高耸，墙上的箭垛里好象还有
人走来走去。阳光照来，城墙上闪过几道白光，似乎是兵器反射出
的光。城门上题着‘西门’两个大字，门口站着一些官兵，正手持
兵刃盘问着来往的行人们。从这里折而向北，就是终南山脚了。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east"      : __DIR__"xijie",
                "northeast" : __DIR__"shanlu",
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
	set("coor/x", -3170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
