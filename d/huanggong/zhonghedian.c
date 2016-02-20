// Room: /d/huanggong/zhonghedian.c

inherit ROOM;

void create()
{
	set("short", "中和殿");
	set("long", @LONG
碉栏玉砌, 金玉堂皇, 这才是皇族气范. 飞檐敞椽, 支撑天地的大
柱正是八部天龙. 这里是紫禁三殿的--中和殿.
    中和取意不偏不倚, 就是说凡事要恰如其份. 这座四角攒尖顶亭式
建筑是皇帝到太和殿参加大典前休息准备和演习礼仪的地方. 每年春播
之季, 皇帝在此阅看种子和农具, 以示殷意. 
LONG
	);
	set("exits", ([
		"north" : __DIR__"baohedian",
		"south" : __DIR__"taihedian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}