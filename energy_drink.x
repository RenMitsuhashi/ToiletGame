xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 166;
 0.00000;8.09465;-1.16490;,
 0.82371;8.09465;-0.82371;,
 1.03950;7.36675;-1.03950;,
 0.00000;7.36675;-1.47008;,
 1.16490;8.09465;0.00000;,
 1.47008;7.36675;0.00000;,
 0.82371;8.09465;0.82371;,
 1.03950;7.36675;1.03950;,
 -0.00000;8.09465;1.16490;,
 -0.00000;7.36675;1.47008;,
 -0.82371;8.09465;0.82371;,
 -1.03950;7.36675;1.03950;,
 -1.16490;8.09465;-0.00000;,
 -1.47008;7.36675;-0.00000;,
 -0.82371;8.09465;-0.82371;,
 -1.03950;7.36675;-1.03950;,
 1.28227;6.71968;-1.28227;,
 0.00000;6.71968;-1.81340;,
 1.81340;6.71968;0.00000;,
 1.28227;6.71968;1.28227;,
 -0.00000;6.71968;1.81340;,
 -1.28227;6.71968;1.28227;,
 -1.81340;6.71968;-0.00000;,
 -1.28227;6.71968;-1.28227;,
 1.51103;6.01126;-1.51103;,
 0.00000;6.01126;-2.13692;,
 2.13692;6.01126;0.00000;,
 1.51103;6.01126;1.51103;,
 -0.00000;6.01126;2.13692;,
 -1.51103;6.01126;1.51103;,
 -2.13692;6.01126;-0.00000;,
 -1.51103;6.01126;-1.51103;,
 1.76777;5.07690;-1.76777;,
 0.00000;5.07690;-2.50000;,
 2.50000;5.07690;0.00000;,
 1.76777;5.07690;1.76777;,
 -0.00000;5.07690;2.50000;,
 -1.76777;5.07690;1.76777;,
 -2.50000;5.07690;-0.00000;,
 -1.76777;5.07690;-1.76777;,
 0.00000;0.64088;-2.50000;,
 1.76777;0.64088;-1.76777;,
 1.70318;0.36816;-1.70318;,
 0.00000;0.36816;-2.40866;,
 2.50000;0.64088;0.00000;,
 2.40866;0.36816;0.00000;,
 1.76777;0.64088;1.76777;,
 1.70318;0.36816;1.70318;,
 -0.00000;0.64088;2.50000;,
 -0.00000;0.36816;2.40866;,
 -1.76777;0.64088;1.76777;,
 -1.70318;0.36816;1.70318;,
 -2.50000;0.64088;-0.00000;,
 -2.40866;0.36816;-0.00000;,
 -1.76777;0.64088;-1.76777;,
 -1.70318;0.36816;-1.70318;,
 1.51924;0.16536;-1.51924;,
 0.00000;0.16536;-2.14853;,
 2.14853;0.16536;0.00000;,
 1.51924;0.16536;1.51924;,
 -0.00000;0.16536;2.14853;,
 -1.51924;0.16536;1.51924;,
 -2.14853;0.16536;-0.00000;,
 -1.51924;0.16536;-1.51924;,
 1.24396;0.01619;-1.24396;,
 0.00000;0.01619;-1.75922;,
 1.75922;0.01619;0.00000;,
 1.24396;0.01619;1.24396;,
 -0.00000;0.01619;1.75922;,
 -1.24396;0.01619;1.24396;,
 -1.75922;0.01619;-0.00000;,
 -1.24396;0.01619;-1.24396;,
 0.91924;0.07916;-0.91924;,
 0.00000;0.07916;-1.30000;,
 1.30000;0.07916;0.00000;,
 0.91924;0.07916;0.91924;,
 -0.00000;0.07916;1.30000;,
 -0.91924;0.07916;0.91924;,
 -1.30000;0.07916;-0.00000;,
 -0.91924;0.07916;-0.91924;,
 0.00000;0.07916;0.00000;,
 0.00000;8.29371;-0.84657;,
 0.59861;8.29371;-0.59861;,
 0.84657;8.29371;0.00000;,
 0.59861;8.29371;0.59861;,
 -0.00000;8.29371;0.84657;,
 -0.59861;8.29371;0.59861;,
 -0.84657;8.29371;-0.00000;,
 -0.59861;8.29371;-0.59861;,
 0.00000;8.61129;-0.84657;,
 0.59861;8.61129;-0.59861;,
 0.00000;8.61129;0.00000;,
 0.84657;8.61129;0.00000;,
 0.59861;8.61129;0.59861;,
 -0.00000;8.61129;0.84657;,
 -0.59861;8.61129;0.59861;,
 -0.84657;8.61129;-0.00000;,
 -0.59861;8.61129;-0.59861;,
 1.77338;4.95565;-1.77338;,
 -0.00000;4.95565;-2.50794;,
 -0.00000;1.61735;-2.50794;,
 1.77338;1.61735;-1.77338;,
 -0.00000;4.95565;-2.50794;,
 1.77338;4.95565;-1.77338;,
 1.77338;1.61735;-1.77338;,
 -0.00000;1.61735;-2.50794;,
 2.50794;4.95565;0.00000;,
 2.50794;1.61735;0.00000;,
 1.77338;4.95565;-1.77338;,
 2.50794;4.95565;0.00000;,
 2.50794;1.61735;0.00000;,
 1.77338;1.61735;-1.77338;,
 1.77338;4.95565;1.77338;,
 1.77338;1.61735;1.77338;,
 1.77338;4.95565;1.77338;,
 1.77338;1.61735;1.77338;,
 -0.00000;4.95565;2.50794;,
 -0.00000;1.61735;2.50794;,
 -0.00000;4.95565;2.50794;,
 -0.00000;1.61735;2.50794;,
 -1.77338;4.95565;1.77338;,
 -1.77338;1.61735;1.77338;,
 -1.77338;4.95565;1.77338;,
 -1.77338;1.61735;1.77338;,
 -2.50794;4.95565;-0.00000;,
 -2.50794;1.61735;-0.00000;,
 -2.50794;4.95565;-0.00000;,
 -2.50794;1.61735;-0.00000;,
 -1.77338;4.95565;-1.77338;,
 -1.77338;1.61735;-1.77338;,
 -1.77338;4.95565;-1.77338;,
 -1.77338;1.61735;-1.77338;,
 0.00000;9.46243;-1.00000;,
 0.70711;9.46243;-0.70711;,
 0.70711;8.57524;-0.70711;,
 0.00000;8.57524;-1.00000;,
 1.00000;9.46243;0.00000;,
 1.00000;8.57524;0.00000;,
 0.70711;9.46243;0.70711;,
 0.70711;8.57524;0.70711;,
 -0.00000;9.46243;1.00000;,
 -0.00000;8.57524;1.00000;,
 -0.70711;9.46243;0.70711;,
 -0.70711;8.57524;0.70711;,
 -1.00000;9.46243;-0.00000;,
 -1.00000;8.57524;-0.00000;,
 -0.70711;9.46243;-0.70711;,
 -0.70711;8.57524;-0.70711;,
 0.00000;9.46243;-1.00000;,
 0.00000;8.57524;-1.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;9.46243;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;,
 0.00000;8.57524;0.00000;;
 
 144;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 4;3,2,16,17;,
 4;2,5,18,16;,
 4;5,7,19,18;,
 4;7,9,20,19;,
 4;9,11,21,20;,
 4;11,13,22,21;,
 4;13,15,23,22;,
 4;15,3,17,23;,
 4;17,16,24,25;,
 4;16,18,26,24;,
 4;18,19,27,26;,
 4;19,20,28,27;,
 4;20,21,29,28;,
 4;21,22,30,29;,
 4;22,23,31,30;,
 4;23,17,25,31;,
 4;25,24,32,33;,
 4;24,26,34,32;,
 4;26,27,35,34;,
 4;27,28,36,35;,
 4;28,29,37,36;,
 4;29,30,38,37;,
 4;30,31,39,38;,
 4;31,25,33,39;,
 4;40,41,42,43;,
 4;41,44,45,42;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 4;50,52,53,51;,
 4;52,54,55,53;,
 4;54,40,43,55;,
 4;43,42,56,57;,
 4;42,45,58,56;,
 4;45,47,59,58;,
 4;47,49,60,59;,
 4;49,51,61,60;,
 4;51,53,62,61;,
 4;53,55,63,62;,
 4;55,43,57,63;,
 4;57,56,64,65;,
 4;56,58,66,64;,
 4;58,59,67,66;,
 4;59,60,68,67;,
 4;60,61,69,68;,
 4;61,62,70,69;,
 4;62,63,71,70;,
 4;63,57,65,71;,
 4;65,64,72,73;,
 4;64,66,74,72;,
 4;66,67,75,74;,
 4;67,68,76,75;,
 4;68,69,77,76;,
 4;69,70,78,77;,
 4;70,71,79,78;,
 4;71,65,73,79;,
 3;73,72,80;,
 3;72,74,80;,
 3;74,75,80;,
 3;75,76,80;,
 3;76,77,80;,
 3;77,78,80;,
 3;78,79,80;,
 3;79,73,80;,
 4;81,82,1,0;,
 4;82,83,4,1;,
 4;83,84,6,4;,
 4;84,85,8,6;,
 4;85,86,10,8;,
 4;86,87,12,10;,
 4;87,88,14,12;,
 4;88,81,0,14;,
 4;89,90,82,81;,
 3;91,90,89;,
 4;90,92,83,82;,
 3;91,92,90;,
 4;92,93,84,83;,
 3;91,93,92;,
 4;93,94,85,84;,
 3;91,94,93;,
 4;94,95,86,85;,
 3;91,95,94;,
 4;95,96,87,86;,
 3;91,96,95;,
 4;96,97,88,87;,
 3;91,97,96;,
 4;97,89,81,88;,
 3;91,89,97;,
 4;98,99,33,32;,
 4;100,101,41,40;,
 4;102,103,104,105;,
 4;106,98,32,34;,
 4;101,107,44,41;,
 4;108,109,110,111;,
 4;112,106,34,35;,
 4;107,113,46,44;,
 4;109,114,115,110;,
 4;116,112,35,36;,
 4;113,117,48,46;,
 4;114,118,119,115;,
 4;120,116,36,37;,
 4;117,121,50,48;,
 4;118,122,123,119;,
 4;124,120,37,38;,
 4;121,125,52,50;,
 4;122,126,127,123;,
 4;128,124,38,39;,
 4;125,129,54,52;,
 4;126,130,131,127;,
 4;99,128,39,33;,
 4;129,100,40,54;,
 4;130,102,105,131;,
 4;132,133,134,135;,
 4;133,136,137,134;,
 4;136,138,139,137;,
 4;138,140,141,139;,
 4;140,142,143,141;,
 4;142,144,145,143;,
 4;144,146,147,145;,
 4;146,148,149,147;,
 3;150,133,132;,
 3;151,136,133;,
 3;152,138,136;,
 3;153,140,138;,
 3;154,142,140;,
 3;155,144,142;,
 3;156,146,144;,
 3;157,148,146;,
 3;158,135,134;,
 3;159,134,137;,
 3;160,137,139;,
 3;161,139,141;,
 3;162,141,143;,
 3;163,143,145;,
 3;164,145,147;,
 3;165,147,149;;
 
 MeshMaterialList {
  3;
  144;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  0,
  2,
  0,
  0,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.483137;0.156863;0.047059;0.890000;;
   22.000000;
   0.540000;0.540000;0.540000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\OneDrive\\�h�L�������g\\���^�Z�R�C�A\\�g�C��\\�G�i�h��.png";
   }
  }
 }
 MeshNormals {
  129;
  -0.000000;0.653013;-0.757347;,
  0.535525;0.653013;-0.535525;,
  0.757347;0.653013;0.000000;,
  0.535525;0.653013;0.535525;,
  -0.000000;0.653013;0.757347;,
  -0.535525;0.653013;0.535525;,
  -0.757347;0.653013;0.000000;,
  -0.535525;0.653013;-0.535525;,
  -0.000000;0.428221;-0.903674;,
  0.638994;0.428221;-0.638994;,
  0.903674;0.428221;0.000000;,
  0.638994;0.428221;0.638994;,
  -0.000000;0.428221;0.903674;,
  -0.638994;0.428221;0.638994;,
  -0.903674;0.428221;0.000000;,
  -0.638994;0.428221;-0.638994;,
  -0.000000;0.442293;-0.896871;,
  0.634183;0.442292;-0.634183;,
  0.896871;0.442293;0.000000;,
  0.634183;0.442292;0.634183;,
  -0.000000;0.442293;0.896871;,
  -0.634183;0.442293;0.634183;,
  -0.896871;0.442293;-0.000000;,
  -0.634184;0.442292;-0.634183;,
  -0.000000;0.389008;-0.921234;,
  0.651411;0.389008;-0.651411;,
  0.921234;0.389008;0.000000;,
  0.651411;0.389008;0.651411;,
  -0.000000;0.389008;0.921234;,
  -0.651411;0.389008;0.651411;,
  -0.921234;0.389008;-0.000000;,
  -0.651411;0.389008;-0.651411;,
  -0.000000;0.216979;-0.976176;,
  0.690261;0.216979;-0.690261;,
  0.976176;0.216979;0.000000;,
  0.690261;0.216979;0.690261;,
  -0.000000;0.216978;0.976176;,
  -0.690261;0.216978;0.690261;,
  -0.976176;0.216978;-0.000000;,
  -0.690261;0.216979;-0.690261;,
  -0.000000;-0.165484;-0.986212;,
  0.697357;-0.165484;-0.697357;,
  0.986212;-0.165484;0.000000;,
  0.697358;-0.165484;0.697358;,
  -0.000000;-0.165484;0.986212;,
  -0.697358;-0.165484;0.697357;,
  -0.986212;-0.165484;-0.000000;,
  -0.697357;-0.165484;-0.697357;,
  -0.000000;-0.582635;-0.812734;,
  0.574690;-0.582635;-0.574690;,
  0.812734;-0.582635;0.000000;,
  0.574690;-0.582635;0.574690;,
  -0.000000;-0.582635;0.812734;,
  -0.574690;-0.582635;0.574690;,
  -0.812734;-0.582635;-0.000000;,
  -0.574690;-0.582635;-0.574690;,
  -0.000000;-0.871516;-0.490367;,
  0.346742;-0.871516;-0.346742;,
  0.490367;-0.871516;0.000000;,
  0.346742;-0.871516;0.346742;,
  -0.000000;-0.871516;0.490367;,
  -0.346742;-0.871516;0.346742;,
  -0.490367;-0.871516;-0.000000;,
  -0.346742;-0.871516;-0.346742;,
  0.000000;-0.993553;-0.113373;,
  0.080167;-0.993553;-0.080167;,
  0.113373;-0.993553;0.000000;,
  0.080167;-0.993553;0.080167;,
  -0.000000;-0.993553;0.113373;,
  -0.080167;-0.993553;0.080167;,
  -0.113373;-0.993553;0.000000;,
  -0.080167;-0.993553;-0.080167;,
  0.000000;-0.997683;0.068031;,
  -0.048105;-0.997683;0.048105;,
  -0.068031;-0.997683;-0.000000;,
  -0.048105;-0.997683;-0.048105;,
  0.000000;-0.997683;-0.068031;,
  0.048105;-0.997683;-0.048105;,
  0.068031;-0.997683;0.000000;,
  0.048105;-0.997683;0.048105;,
  0.000000;-1.000000;-0.000000;,
  -0.000000;0.847876;-0.530195;,
  0.374905;0.847876;-0.374905;,
  0.530195;0.847876;-0.000000;,
  0.374904;0.847876;0.374905;,
  -0.000000;0.847876;0.530195;,
  -0.374905;0.847876;0.374904;,
  -0.530195;0.847876;0.000000;,
  -0.374905;0.847876;-0.374904;,
  -0.000000;1.000000;-0.000000;,
  -0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;-0.000000;,
  0.707107;0.000000;0.707107;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.000000;-0.707107;,
  -0.000000;0.032683;-0.999466;,
  0.706729;0.032683;-0.706729;,
  0.999466;0.032683;0.000000;,
  0.706729;0.032683;0.706729;,
  -0.000000;0.032683;0.999466;,
  -0.706729;0.032682;0.706729;,
  -0.999466;0.032682;0.000000;,
  -0.706729;0.032683;-0.706729;,
  -0.000000;-0.004064;-0.999992;,
  0.707101;-0.004064;-0.707101;,
  0.999992;-0.004064;0.000000;,
  0.707101;-0.004064;0.707101;,
  -0.000000;-0.004064;0.999992;,
  -0.707101;-0.004064;0.707101;,
  -0.999992;-0.004064;0.000000;,
  -0.707101;-0.004064;-0.707101;,
  -0.000000;1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  -0.000001;1.000000;-0.000001;,
  -0.000001;1.000000;-0.000000;,
  -0.000001;1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  -0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;-0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;-1.000000;-0.000000;;
  144;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  4;24,25,33,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,24,32,39;,
  4;40,41,49,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,40,48,55;,
  4;48,49,57,56;,
  4;49,50,58,57;,
  4;50,51,59,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;54,55,63,62;,
  4;55,48,56,63;,
  4;56,57,65,64;,
  4;57,58,66,65;,
  4;58,59,67,66;,
  4;59,60,68,67;,
  4;60,61,69,68;,
  4;61,62,70,69;,
  4;62,63,71,70;,
  4;63,56,64,71;,
  4;64,65,73,72;,
  4;65,66,74,73;,
  4;66,67,75,74;,
  4;67,68,76,75;,
  4;68,69,77,76;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,64,72,79;,
  3;72,73,80;,
  3;73,74,80;,
  3;74,75,80;,
  3;75,76,80;,
  3;76,77,80;,
  3;77,78,80;,
  3;78,79,80;,
  3;79,72,80;,
  4;81,82,1,0;,
  4;82,83,2,1;,
  4;83,84,3,2;,
  4;84,85,4,3;,
  4;85,86,5,4;,
  4;86,87,6,5;,
  4;87,88,7,6;,
  4;88,81,0,7;,
  4;90,91,91,90;,
  3;89,114,115;,
  4;91,92,92,91;,
  3;89,116,114;,
  4;92,93,93,92;,
  3;89,117,116;,
  4;93,94,94,93;,
  3;89,118,117;,
  4;94,95,95,94;,
  3;89,115,118;,
  4;95,96,96,95;,
  3;89,115,115;,
  4;96,97,97,96;,
  3;89,115,115;,
  4;97,90,90,97;,
  3;89,115,115;,
  4;99,98,32,33;,
  4;106,107,41,40;,
  4;98,99,107,106;,
  4;100,99,33,34;,
  4;107,108,42,41;,
  4;99,100,108,107;,
  4;101,100,34,35;,
  4;108,109,43,42;,
  4;100,101,109,108;,
  4;102,101,35,36;,
  4;109,110,44,43;,
  4;101,102,110,109;,
  4;103,102,36,37;,
  4;110,111,45,44;,
  4;102,103,111,110;,
  4;104,103,37,38;,
  4;111,112,46,45;,
  4;103,104,112,111;,
  4;105,104,38,39;,
  4;112,113,47,46;,
  4;104,105,113,112;,
  4;98,105,39,32;,
  4;113,106,40,47;,
  4;105,98,106,113;,
  4;120,121,121,120;,
  4;121,122,122,121;,
  4;122,123,123,122;,
  4;123,124,124,123;,
  4;124,125,125,124;,
  4;125,126,126,125;,
  4;126,127,127,126;,
  4;127,120,120,127;,
  3;119,119,119;,
  3;119,119,119;,
  3;119,119,119;,
  3;119,119,119;,
  3;119,119,119;,
  3;119,119,119;,
  3;119,119,119;,
  3;119,119,119;,
  3;128,128,128;,
  3;128,128,128;,
  3;128,128,128;,
  3;128,128,128;,
  3;128,128,128;,
  3;128,128,128;,
  3;128,128,128;,
  3;128,128,128;;
 }
 MeshTextureCoords {
  166;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;-1.022361;,
  1.125000;-1.022361;,
  1.125000;0.003157;,
  1.000000;0.003157;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.125000;-1.022361;,
  0.250000;-1.022361;,
  0.250000;0.003157;,
  0.125000;0.003157;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.375000;-1.022361;,
  0.375000;0.003157;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.500000;-1.022361;,
  0.500000;0.003157;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.625000;-1.022361;,
  0.625000;0.003157;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.750000;-1.022361;,
  0.750000;0.003157;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.875000;-1.022361;,
  0.875000;0.003157;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}