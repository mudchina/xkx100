// Room: /d/yanping/yanshoumen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "延寿门");
	set("long", @LONG
延寿门是延平府南门，门高可两丈，青砖砌就，上垒敌楼，即名延
寿楼。国姓爷郑成功为救隆武天子的驾，曾登陴督战。清人有诗：“虎
踞竣(山曾)此一关，建瓴高屋俯千湾。归云峡口三溪水，横翠峰前百丈
山。忠定谪来官舍冷，龟山老去讲堂闲。垂虹阁向龙津倚，烛汉星光隐
照颜。”门外浮桥通往西溪南岸的九峰山。
LONG );
	set("exits", ([
		"north"     : __DIR__"road2",
		"southdown" : __DIR__"fuqiao2",
	]));
        set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
