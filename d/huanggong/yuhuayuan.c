// yuhuayuan.c 御花园

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
这里是皇上赏花的御花园. 平日里皇上时常会来这儿, 和贵妃娘娘
一起赏花品茗. 所以, 这儿是平常太监, 侍卫不能来的. 这里的宫女多
是心灵手巧, 精通花道的. 放眼四顾, 满目皆是似锦繁花, 你仔细分辨, 
竟然品目齐全, 大凡你想得的, 甚至你想都不敢想的, 这里都有了. 你
不禁有些妒嫉起皇帝老儿来.
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"north" : __DIR__"yuhuayuan2",
		"south" : __DIR__"kunningmen",
		"northeast" : __DIR__"fubiting",
		"northwest" : __DIR__"chengruiting",
		"southeast" : __DIR__"wanchunting",
		"southwest" : __DIR__"qianqiuting",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 2,
		__DIR__"obj/panlonghuai" : 1,
		__DIR__"obj/wolongsong" : 1,
		__DIR__"obj/luohanbai" : 1,
	]) );
	set("coor/x", -200);
	set("coor/y", 5330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}