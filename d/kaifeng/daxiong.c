// /kaifeng/daxiong.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
经过九级石头台阶，正面就是佛祖神像，两边普贤和文殊。高大的
佛像几乎挨到了屋顶，令人凌然生威。正对着门的地方摆着几张供桌，
上面是时鲜的瓜果。供桌两边的大蜡烛比人还高。两边是十八罗汉。
LONG);
	set("objects", ([
		__DIR__"npc/obj/rulaixiang" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"zhongyuan",
		"north" : __DIR__"houyuan",
	]));

	setup();
	replace_program(ROOM);
}
