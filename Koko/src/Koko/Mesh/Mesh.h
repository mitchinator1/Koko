#ifndef MESH_H
#define MESH_H
#include "GLM/glm.hpp"
#include "VertexArray.h"

class Texture;

class Mesh
{
private:
	std::unique_ptr<VertexArray> m_VA;
	Texture* m_Texture;
	glm::mat4 m_ModelMatrix;
	int m_Mode;

public:
	Mesh(const std::vector<float>& vertices, unsigned int count, unsigned int stride, const std::vector<unsigned int>& indices = { });
	Mesh(const std::vector<float>& vertices, const std::vector<unsigned int> strides = { 3, 4 }, const std::vector<unsigned int>& indices = { });
	~Mesh();

	void Bind()		const;
	void Unbind()	const;

	void UpdateVertices(const std::vector<float>& vertices, unsigned int set = 2);
	void UpdateIndices(const std::vector<unsigned int>& indices);
	void UpdateCount(unsigned int count);

	void SetTexture(Texture* texture);
	void SetMode(unsigned int mode);

	inline auto GetCount()			const { return m_VA->GetCount(); }
	inline auto& GetModelMatrix()	const { return m_ModelMatrix; }
	inline auto GetMode()				  { return m_Mode; }

private:
	std::vector<unsigned int> CalculateIndices(const std::vector<float>& vertices, unsigned int set);

};

#endif