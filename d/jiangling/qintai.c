//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "古琴台");
	set ("long", @LONG
这里又名伯牙台。相传春秋战国时期，楚国琴师俞伯牙路经汉阳，
夜泊江岸，当晚雨后月朗天清，伯牙抚琴抒怀，樵夫钟子期路过，听罢
一曲《高山流水》，情不自禁赞道：“峨峨兮若泰山，洋洋兮若江河”。
伯牙巧遇知音，大为高兴。两人相约半年后来此一聚。第二年，子期不
幸病逝，伯牙悲痛欲绝，来到子期墓前，重弹《高山流水》，并将七弦
琴摔碎，长歌痛哭。后人为了纪念这个“摔琴谢知音”的故事，建了这
个琴台。琴台中央石碑上刻有伯牙半身像。北面有一座飞檐高耸的亭子。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"north" : __DIR__"qinguan",
		"west"  : __DIR__"hzjie3",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
