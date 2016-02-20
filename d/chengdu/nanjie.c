// Room: /d/chengdu/nanjie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在南大街的最南端，道路两旁栽种着枝粗叶茂的梧桐，路面被
打扫得干干净净。来来往往的都是些兵勇和官员，偶尔走过来几个平民
百姓。西边是一座古朴的祠堂，香火缭绕，游人络绎不绝，那就是川人
所共同敬仰的武侯祠。东面有个制作精致的石拱桥。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"      : __DIR__"gongqiao",
		"west"      : __DIR__"wuhoucigate",
		"north"     : __DIR__"nanjie2",
		"south"     : __DIR__"southgate",
		"southwest" : __DIR__"cai",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

