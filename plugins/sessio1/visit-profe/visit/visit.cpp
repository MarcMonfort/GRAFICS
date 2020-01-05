#include "visit.h"
#include "glwidget.h"

void Visit::info()
{
	const auto& objs = scene()->objects();
	int nobj = objs.size();
	cout << endl << "Scene with " << nobj << " object(s)" << endl; 
	for (auto&& obj : objs) // for every object
	{
		cout << " Object: "	<< endl;

		cout << "  Vertices: " << endl;
		const auto& vertices = obj.vertices();		
		for (unsigned int i=0; i<vertices.size(); ++i) // for every vertex
		{
			const Vertex& vertex = vertices[i];
			const Point& P = vertex.coord();
			cout << "   V " << i << ":  " << P.x() << ", " << P.y() << ", " << P.z() << endl;
		}

		cout << "  Faces: " << endl;
		const auto& faces = obj.faces();		
		for (unsigned int i=0; i<faces.size(); ++i) // for every faces
		{
			const Face& face = faces[i];
			unsigned int numVerts = face.numVertices(); // usually 3 (triangular faces)
			cout << "   F " << i << ":  " ;
			for (unsigned int j=0; j<numVerts; ++j) // for every vertex of the face
				cout << face.vertexIndex(j) << " ";
			cout << endl;
		}
	
	}
}

void Visit::onPluginLoad()
{
	info();
}


void Visit::onObjectAdd()
{
	info();
}


void Visit::keyPressEvent(QKeyEvent *)
{
	info();
}

