// Room: /d/wuxi/taibomiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "泰伯庙");
	set("long", @LONG
早在远古时期，泰伯奔吴，在这里传授当地人识字、纺织、发展陶
瓷业的冶铜业，和奠定了江南文化的基础。泰伯也因此受到了当地人民
的敬重和爱戴。人们来此大多放下武器，恭恭敬敬的立于一旁进香磕头。
如今无锡城发展了，除了逢年初九泰伯诞辰之日外，来这里的人也不多
见了。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"road9",
		"west" : "/d/guiyun/road1",
	]));
	set("coor/x", 340);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
