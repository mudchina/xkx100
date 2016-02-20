// Room: /d/5lt/shijie.c

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
你走在青石板铺成的石阶上。这些日子雨下个不停，石阶上生成点
点苔藓，路面有些湿滑。淡淡烟雨中，你可以望见石阶羊肠似的一路延
伸上去，就像是一条怪蛇弯曲着向上爬行，直入青云。
LONG);
        set("exits", ([ /* sizeof() == 1 */
            "northdown" : __DIR__"wroad3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -180);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}