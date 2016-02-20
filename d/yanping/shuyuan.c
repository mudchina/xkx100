// Room: /d/yanping/shuyuan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "延平书院");
	set("long", @LONG
建于宋嘉定二年，郡守陈宓于九峰山麓，仿白鹿书院创建此延平书
院，为“延平四贤”讲学之所，书院建于九峰山号称“金交椅”的山凹
之处。此处“日受千人拜，夜享万盏灯”，为延平风水绝佳之地。堂上
坐着一个先生，身后是一个书架，摆满了各种典籍。先生正据案奋笔疾
书，似乎在赶着甚么学问。原来他就是黄裳啊，他曾修《万寿道藏》，
无师自通，修习内功外功，竟成为一位武功大高手，写下了武林无上密
笈《九阴真经》。
LONG );
	set("exits", ([
		"west"      : __DIR__"9fengshan",
		"southeast" : __DIR__"yuandong",
	]));
	set("objects", ([
		__DIR__"npc/huangshang" : 1,
	]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
