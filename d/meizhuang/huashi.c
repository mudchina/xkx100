// d/meizhuang/huashi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "画室");
	set("long", @LONG
这里是丹青生的画室，俗话说：书画不分家，所以丹青生的书法也
有相当的功力，虽然不及他三哥秃笔翁很多，但他将他的剑法融于他的
书法当中，也可谓是银钩铁划了。这里的陈设和书室差不多，唯一不同
的是这里的墙上并没有挂丹青生的丹青妙笔，而是挂了许多前朝名家的
名画，属于丹青生自己的是一幅写着《兵车行》的中堂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/sheng.c" : 1,
	]));

	set("coor/x", 3510);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
