// Room: /d/taohua/sixiang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "四象");
	set("long", @LONG
这里是四象层，你一走下来，往上的铁梯就被撤掉了。所谓四象，
系指阴阳变化的四态，亦即太阴、少阳、太阳、少阴，是阴阳互相转化
的形式。阴极中的阴就是太阴，而阴中带阳就是少阳，同样的也有太阳
和少阴。四象进一步演化即是四象生八卦，以方位倒转八卦论，太阳之
阳为乾，居正南，太阴之阴为坤，于正北；少阴之阳为离，居东方，少
阳之阴为坎，在西方。四象又对应五灵中的四兽，而此室居中央，表示
五灵中的人统领其余四灵兽。以方位入五行，此中土之形，尚黄，有一
道铁梯直通下方的中央戊己土。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"taiyin",
		"south" : __DIR__"taiyang",
		"west" : __DIR__"shaoyang",
		"east" : __DIR__"shaoyin",
		"down" : __DIR__"tu",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}