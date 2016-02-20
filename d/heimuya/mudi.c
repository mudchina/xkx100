// Room: /d/heimuya/mudi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "墓地");
	set("long", @LONG
这里是黑木崖日月神教教众的墓地。墓地的周围种了一些矮矮的花
树。树上的白花星星点点。白花中间是一高大的石碑 (bei)，整个墓地
干干净净，显然天天有人打扫。
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
        	"west"      : __DIR__"grass1",
        ]));
	set("item_desc", ([
        	"bei": "上面刻着：神教子民，永生不灭。\n"
	]));
        set("no_clean_up", 0);
	set("coor/x", -3020);
	set("coor/y", 4010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}